import threading

from queue import Queue
from surscriber import subZMQ
from aqua_visu import plot

def main(prot):
    q = Queue()

    t1 = threading.Thread(target=subZMQ, args=(prot, q))
    t2 = threading.Thread(target=plot, args=(q,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

if __name__ == "__main__":
    prot = "tcp://127.0.0.1:5000"
    main(prot)