import sys
import math
import numpy as np
import time

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

class Point(object):

	def __init__(self, vec):
		self.vec = vec.copy()

	def copy_point(self):
		return Point(self.vec)

	def equal_point(self, p):
		return np.all(self.vec == p.vec)

	def square_distance(self, p):
		return sum((self.vec - p.vec) ** 2)

	def distance(self, p):
		return math.sqrt(self.square_distance(p))

class Disk(Point):

	def __init__(self, vec, r=0):
		super(Disk, self).__init__(vec)
		self.r = r

	def copy_disk(self):
		return Disk(self.vec, self.r)

	def equal_disk(self, disk):
		return self.equal_point(disk) and self.r == disk.r
	
	def dist_from_point_to_disk(self, p):
		d = self.distance(p)
		if d <= self.r:
			return 0
		return d - self.r

	def point_of_inter_with_point_and_disk(self, p):
		d = self.distance(p)
		if d <= self.r:
			return p.point_copy()
		return Point(((d - self.r) * self.vec + self.r * p.vec) / d)

	def dist_from_disk_to_disk(self, disk):
		d = self.distance(disk)
		if d <= self.r + disk.r:
			return 0
		return d - self.r - disk.r

class Unit(Disk):

	def __init__(self, vec, r=0, id=0, v_vec=np.array((0, 0)), mass=0, friction=0, angle=0):
		super(Unit, self).__init__(vec)
		self.id = id
		self.v_vec = v_vec.copy()
		self.mass = mass
		self.friction = friction
		self.angle = angle
		self.rad_angle = math.radians(angle)

	def copy_unit(self, id=-1):
		if id == -1:
			id = self.id
		
		return Unit(self.vec, self.r, id, self.v_vec, self.mass, self.friction, self.angle)

	def debug_print(self):
		print("---------------", file=sys.stderr, flush=True)
		print("id:", self.id, file=sys.stderr, flush=True)
		print("vec:", self.vec, file=sys.stderr, flush=True)
		print("v_vec:", self.v_vec, file=sys.stderr, flush=True)
		print("angle:", self.angle, file=sys.stderr, flush=True)
		print("---------------", file=sys.stderr, flush=True)

	def rad_angle_with_point(self, p):
		if self.equal_point(p):
			return self.rad_angle
		d = self.distance(p)
		d_vec = p.vec - self.vec
		theta = math.acos(d_vec[0] / d)
		if d_vec[1] < 0:
			theta = theta * -1
		return theta

	# def get_angle(self):
	# 	p = Point(self.vec + self.v_vec)
	# 	self.angle = self.rad_angle_with_point(p)

	def rad_diff_angle_with_point(self, p):
		angle = self.rad_angle_with_point(p)
		if self.rad_angle <= angle:
			right = angle - self.rad_angle
			left = self.rad_angle + 2 * math.pi - angle
		else:
			right = 2 * math.pi - self.rad_angle + angle
			left = self.rad_angle - angle
		return right if right < left else -left

	def rotate(self, angle, mode='add'):
		if mode == 'add':
			self.angle += angle
		else:
			self.angle = angle
		self.angle += 180
		self.angle %= 360
		self.angle -= 180
		self.rad_angle = math.radians(self.angle)

	def boost(self, thrust):
		if self.mass == 0:
			return
		direction_vec = np.array((math.cos(self.rad_angle), math.sin(self.rad_angle)))
		self.v_vec = self.v_vec + direction_vec * thrust / self.mass

	def move(self, time):
		self.vec = self.vec + self.v_vec * time

	def vec_round_and_friction(self):
		self.vec = np.round(self.vec).astype(int)
		self.v_vec = np.round(self.v_vec * self.friction).astype(int)


class Checkpoint(Disk):
	def __init__(self, vec, r=0, id=0):
		super(Checkpoint, self).__init__(vec, r)
		self.id = id



# class Pod(Unit):

# 	def __init__(self, vec, r=0, id=0, v_vec=np.array((0, 0)), mass=0, friction=0, angle=0):
# 		super(Pod, self).__init__(vec, r, id, v_vec, mass, friction, angle)

# 	def copy_pod(self, id=-1):
# 		if id == -1:
# 			id = self.id
# 		return Pod(self.vec, self.r, id, self.v_vec, self.mass, self.friction, self.angle)


class Move(object):
	def __init__(self, angle, thrust):
		self.angle = angle
		self.thrust = thrust
		self.rad_target_angle = 0
		self.target_point = None
		self.print_point = None

	def set_unit_move(self, target):
		self.angle = np.clip(self.angle, -18, 18)
		target.rotate(self.angle)
		self.rad_target_angle = math.radians(target.angle)
		self.target_point = target.copy_point()
		target.boost(self.thrust)

	def print_parameter(self):
		self.print_point = Point(np.round(self.target_point.vec + 100 * np.array((math.cos(self.rad_target_angle), math.sin(self.rad_target_angle)))).astype(int))
		print(str(self.print_point.vec[0]) + " " + str(self.print_point.vec[1]) + " " + str(self.thrust))



class Solution(object):
	def __init__(self, random_state=42):
		self.random_state = random_state
	
	def solution(self, game):
		unit = game.my_unit
		checkpoint = game.checkpoints[game.target_checkpoint]
		target_point = checkpoint.point_of_inter_with_point_and_disk(unit)
		rad_angle = unit.rad_diff_angle_with_point(target_point)

		game.debug_print_angle(round(math.degrees(rad_angle)), 0)

		thrust = self.decision_thrust(game , math.degrees(rad_angle))
		move = Move(round(math.degrees(rad_angle)), thrust)
		move.set_unit_move(unit)

		unit.move(1)
		unit.vec_round_and_friction()

		move.print_parameter()

	def decision_thrust(self, game, angle):
		unit = game.my_unit
		checkpoint = game.checkpoints[game.target_checkpoint]		
		dist = checkpoint.dist_from_point_to_disk(unit)
		dist_flag = np.clip(int(dist / (math.sqrt(np.sum(unit.v_vec ** 2) + 1e-10))) + 2 , 3, 5)
		checkpoint_flag = np.clip(int((108 - abs(angle)) / 18), 1, 5)
		
		next_checkpoint_flag = 0
		if game.target_checkpoint < len(game.checkpoints) - 1:
			next_checkpoint = game.checkpoints[game.target_checkpoint + 1]
			next_angle = math.degrees(unit.rad_diff_angle_with_point(next_checkpoint))
			next_checkpoint_flag = np.clip(int((108 - abs(next_angle)) / 18), 1, 5)

		return 20 * min(checkpoint_flag, max(dist_flag, next_checkpoint_flag))






class Gamedata(object):
	def __init__(self):
		self.my_unit = None
		self.checkpoints = []
		self.target_checkpoint = 0
		self.turn = 0

		self.opponent_unit = None
		self.next_checkpoint_dist = 0
		self.next_checkpoint_angle = 0
		self.debug_count = 0

	def debug_print_vec(self, x, y):
		print("---------------", file=sys.stderr, flush=True)
		print("id:", self.my_unit.id, file=sys.stderr, flush=True)
		print("my_vec:", self.my_unit.vec, file=sys.stderr, flush=True)
		print("true_vec:", [x, y], file=sys.stderr, flush=True)
		print("diff_vec:", np.array((x, y)) - self.my_unit.vec, file=sys.stderr, flush=True)
		print("---------------", file=sys.stderr, flush=True)

	def debug_print_angle(self, angle, mode):
		if mode == -1:
			print("---------------", file=sys.stderr, flush=True)
			print("id:", self.my_unit.id, file=sys.stderr, flush=True)
			print("my_angle:", angle, file=sys.stderr, flush=True)
			print("true_angle:", self.next_checkpoint_angle, file=sys.stderr, flush=True)
			print("diff_angle:", self.next_checkpoint_angle - angle, file=sys.stderr, flush=True)
			print("---------------", file=sys.stderr, flush=True)
		elif abs(self.next_checkpoint_angle - angle) > mode:
			print("---------------", file=sys.stderr, flush=True)
			print("id:", self.my_unit.id, file=sys.stderr, flush=True)
			self.debug_count += 1
			print("debug_count:", self.debug_count, file=sys.stderr, flush=True)
			print("my_angle:", angle, file=sys.stderr, flush=True)
			print("true_angle:", self.next_checkpoint_angle, file=sys.stderr, flush=True)
			print("diff_angle:", self.next_checkpoint_angle - angle, file=sys.stderr, flush=True)
			print("---------------", file=sys.stderr, flush=True)


	def first_input(self):
		x, y, next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle = [int(i) for i in input().split()]
		opponent_x, opponent_y = [int(i) for i in input().split()]
		self.my_unit = Unit(np.array((x, y)), 0, 1, np.array((0, 0)), 1, 0.85, 0)
		self.checkpoints.append(Checkpoint(np.array((next_checkpoint_x, next_checkpoint_y)), 600, 10))
		self.my_unit.rad_angle = self.my_unit.rad_angle_with_point(self.checkpoints[0])
		self.my_unit.angle = math.degrees(self.my_unit.rad_angle)
		
		self.opponent_unit = Unit(np.array((opponent_x, opponent_y)), 0, 2, np.array((0, 0)), 1, 0.75, 0)
		self.next_checkpoint_dist = next_checkpoint_dist
		self.next_checkpoint_angle = next_checkpoint_angle

	def input(self):
		x, y, next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle = [int(i) for i in input().split()]
		opponent_x, opponent_y = [int(i) for i in input().split()]

		self.my_unit.debug_print()
		self.debug_print_vec(x, y)

		self.my_unit.vec = np.array((x, y))
		next_checkpoint = np.array((next_checkpoint_x, next_checkpoint_y))
		if np.any(self.checkpoints[self.target_checkpoint] != next_checkpoint):
			if np.any(self.checkpoints[0] != next_checkpoint):
				self.target_checkpoint += 1
				self.checkpoints.append(Checkpoint(next_checkpoint, 600, 10 + self.target_checkpoint))
			else:
				self.target_checkpoint = 0
		
		self.opponent_unit.vec = np.array((opponent_x, opponent_y))
		self.next_checkpoint_dist = next_checkpoint_dist
		self.next_checkpoint_angle = next_checkpoint_angle








game = Gamedata()
solution = Solution()
game.first_input()

while True:
	if game.turn != 0:
		game.input()
	solution.solution(game)
	game.turn += 1



# my_unit = Unit(np.array((0, 0)))
# # game loop
# while True:
# 	# next_checkpoint_x: x position of the next check point
# 	# next_checkpoint_y: y position of the next check point
# 	# next_checkpoint_dist: distance to the next checkpoint
# 	# next_checkpoint_angle: angle between your pod orientation and the direction of the next checkpoint
# 	x, y, next_checkpoint_x, next_checkpoint_y, next_checkpoint_dist, next_checkpoint_angle = [int(i) for i in input().split()]
# 	opponent_x, opponent_y = [int(i) for i in input().split()]

# 	# Write an action using print
# 	# To debug: print("Debug messages...", file=sys.stderr, flush=True)


# 	# You have to output the target position
# 	# followed by the power (0 <= thrust <= 100)
# 	# i.e.: "x y thrust"


# 	my_unit = Unit(np.array((x, y)), 0, 0, np.array((x, y)) - my_unit.vec, 1)
# 	v = math.sqrt(sum(my_unit.v_vec ** 2))
# 	checkpoint = Disk(np.array((next_checkpoint_x, next_checkpoint_y)), 600)

# 	angle = my_unit.rad_diff_angle_with_point(checkpoint)
# 	angle = math.degrees(angle)
# 	diff = next_checkpoint_angle - angle

	
# 	print("my_v_vec:", my_unit.v_vec, file=sys.stderr, flush=True)
# 	print("v:", v, file=sys.stderr, flush=True)
# 	print("my_angle:", angle, file=sys.stderr, flush=True)
# 	print("true_angle:", next_checkpoint_angle, file=sys.stderr, flush=True)
# 	print("angle_diff:", diff, file=sys.stderr, flush=True)
# 	if next_checkpoint_angle > 70 or next_checkpoint_angle < -70 or next_checkpoint_dist < 1000:
# 		print(str(next_checkpoint_x) + " " + str(next_checkpoint_y) + " 0")
# 	else:
# 		print(str(next_checkpoint_x) + " " + str(next_checkpoint_y) + " 100")