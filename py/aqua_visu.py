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

def plot(queue, delta = None):
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
    reader.getFullDataFlux(q)
    plot(q, 0)
    print("------------------END-------------------")