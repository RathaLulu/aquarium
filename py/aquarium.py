import json
import numpy as np
import pygame

BLUE = (0, 128, 255)
ORANGE = (255, 150, 0)
RED = (255, 50, 50)
GREEN = (50, 255, 50)


class aquarium : 
    def __init__(self, json_epoch, surface):
        self.Nepoch = json_epoch['tour']
        self.surface = surface
        self.poissons = [poisson(p,self.surface) for p in json_epoch['poissons']]

    def draw(self) :
        for poisson in self.poissons: 
            poisson.draw()

class poisson: 

    def __init__(self, json_poisson, surface): 
        self.json = json_poisson
        self.name = json_poisson['name']
        self.type = json_poisson['type']
        self.X = np.array([json_poisson['pos']['x'], json_poisson['pos']['y']])
        self.V = np.array([json_poisson['pos']['vx'], json_poisson['pos']['vy']])
        self.flip = self.V[0]<0
        self.pv = json_poisson['life']
        self.surface = surface 

    def draw(self):
        """
        Dessine un poisson simple.
        flip=True : le poisson regarde vers la gauche
        """

        if self.type == 'CARNIVORE':
            color = RED
        elif self.type == 'HERBIVORE': 
            color = GREEN
        else : 
            color = ORANGE


        WIDTH, HEIGHT = self.surface.get_size()
        x = (self.X[0]) / 20 * WIDTH *2
        y = (self.X[1]) / 20 * HEIGHT * 2 

        size = max(1, int(self.pv))
        body_width = size * 2
        body_height = size
        tail_size = size

        if self.flip:
            # Corps
            pygame.draw.ellipse(self.surface, color, (x - body_width, y, body_width, body_height))
            # Queue
            tail = [(x, y + body_height // 2),
                    (x + tail_size, y),
                    (x + tail_size, y + body_height)]
            pygame.draw.polygon(self.surface, color, tail)
        else:
            # Corps
            pygame.draw.ellipse(self.surface, color, (x, y, body_width, body_height))
            # Queue
            tail = [(x, y + body_height // 2),
                    (x - tail_size, y),
                    (x - tail_size, y + body_height)]
            pygame.draw.polygon(self.surface, color, tail)

