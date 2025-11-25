import pygame
import json
import time

from queue import Queue
from fileaqua_reader import aqua_reader
from aquarium import aquarium, poisson

BLUE = (0, 128, 255)
ORANGE = (255, 150, 0)
RED = (255, 50, 50)
GREEN = (50, 255, 50)

class plot_aqua : 
    def __init__(self, name, size, data):
        if len(size) != 2 : 
            raise ValueError("Size doit etre une liste avec exactement deux élements")
        self.name = name
        self.size = size 

    # --- Fonction pour dessiner un poisson ---
    def draw_fish(surface, color, x, y, size, flip=False):
        """
        Dessine un poisson simple.
        flip=True : le poisson regarde vers la gauche
        """
        body_width = size * 2
        body_height = size
        tail_size = size

        if flip:
            # Corps
            pygame.draw.ellipse(surface, color, (x - body_width, y, body_width, body_height))
            # Queue
            tail = [(x, y + body_height // 2),
                    (x + tail_size, y),
                    (x + tail_size, y + body_height)]
            pygame.draw.polygon(surface, color, tail)
        else:
            # Corps
            pygame.draw.ellipse(surface, color, (x, y, body_width, body_height))
            # Queue
            tail = [(x, y + body_height // 2),
                    (x - tail_size, y),
                    (x - tail_size, y + body_height)]
            pygame.draw.polygon(surface, color, tail)

def plot(queue, delta) :
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("Aquarium Animé")
    clock = pygame.time.Clock()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        screen.fill(BLUE)  # Fond "aquarium"
        epoch = queue.get()
        aqua = aquarium(epoch, screen)
        print(aqua.poissons[0].X)
        aqua.draw()
        pygame.display.flip()
        clock.tick(1)

        






if __name__ == "__main__":
    print("-----------------START------------------")
    filename = f'/home/lucas/code/aquarium/data/test.json'
    reader = aqua_reader(filename)
    q = Queue()
    reader.getDataFlux(q)
    plot(q, 0)
    print("------------------END-------------------")