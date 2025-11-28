import zmq
import json 

from queue import Queue

def subZMQ(prot ,queue): 
    ctx = zmq.Context()
    sock = ctx.socket(zmq.SUB)
    sock.connect(prot)
    sock.setsockopt_string(zmq.SUBSCRIBE, "")
    try:
        while True:
            msg = sock.recv_string()
            queue.put(json.loads(msg))
            print(json.loads(msg))
    except KeyboardInterrupt:
        print("arret")

if __name__ == "__main__":
    q = Queue() 
    serverZMQ("tcp://127.0.0.1:5000", q)



