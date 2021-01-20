import pygame

class Settings:
	"""A class to store all settings for Alien Invasion."""

	def __init__(self):
		"""Initialize the game's static settings."""
		# Bullet settings
		self.bullet_width = 5
		self.bullet_height = 10
		self.bullet_color = (255, 0, 60)
		self.bullets_allowed = 30

		# Screen settings
		self.screen_width = 1200
		self.screen_height = 800
		self.bg_image = pygame.image.load('images/background.jpg')

		# Ship Settings
		self.ship_limit = 3

		# Alien settings
		self.fleet_drop_speed = 10
		
		# How quickly the game speeds up
		self.speedup_scale = 1.1

		# How quickly the alien point values increase after each level
		self.score_scale = 1.5

		self.clock = pygame.time.Clock()
		

		self.initialize_dynamic_settings()


	def initialize_dynamic_settings(self):
		"""Initialize settings that change throughout the game."""
		self.ship_speed = 4.5
		self.bullet_speed = 5.0
		self.alien_speed = 2.0

		# Scoring
		self.alien_points = 50

		# fleet_direction of 1 represents right; -1 represents left
		self.fleet_direction = 1

	def increase_speed(self):
		"""Increase speed settings and alien point values."""
		self.ship_speed *= self.speedup_scale
		self.bullet_speed *= self.speedup_scale
		self.alien_speed *= self.speedup_scale

		self.alien_points = int(self.alien_points * self.score_scale)