import pygame
import random
#!!! Exemple de chatgpt 
# --- Initialisation ---
pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Aquarium Animé")
clock = pygame.time.Clock()

# --- Couleurs ---
BLUE = (0, 128, 255)
ORANGE = (255, 150, 0)
RED = (255, 50, 50)
GREEN = (50, 255, 50)

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

# --- Classe Poisson ---
class Fish:
    def __init__(self, x, y, color, size):
        self.x = x
        self.y = y
        self.color = color
        self.size = size
        # Vitesse aléatoire
        self.vx = random.choice([-2, -1, 1, 2])
        self.vy = random.choice([-1, 1])
    
    def move(self, width, height):
        self.x += self.vx
        self.y += self.vy

        # Rebond sur les bords
        if self.x < 0 or self.x > width - self.size * 2:
            self.vx *= -1
        if self.y < 0 or self.y > height - self.size:
            self.vy *= -1

    def draw(self, surface):
        flip = self.vx < 0
        draw_fish(surface, self.color, int(self.x), int(self.y), self.size, flip)

# --- Créer des poissons ---
fishes = [
    Fish(400, 200, ORANGE, 20),
    Fish(300, 400, RED, 25),
    Fish(600, 300, GREEN, 15),
    Fish(200, 150, (200, 200, 0), 18),  # ajout d'un poisson supplémentaire
    Fish(500, 500, (255, 0, 255), 22)
]

# --- Boucle principale ---
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill(BLUE)  # Fond "aquarium"

    # Déplacer et dessiner chaque poisson
    for fish in fishes:
        fish.move(screen.get_width(), screen.get_height())
        fish.draw(screen)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()