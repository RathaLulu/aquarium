import zmq
import time
import signal
import json 


from fileaqua_reader import aqua_reader

def handler(sig, frame):
    print("\nCtrl+C reçu")
    sys.exit(0)


def clientZMQ(filename, prot, timesleep): 
    signal.signal(signal.SIGINT, handler)
    ctx = zmq.Context()
    sock = ctx.socket(zmq.PUB)
    sock.bind(prot)
    reader = aqua_reader(filename)
    while True : 
        for i in range(1, reader.size): 
            epoch = reader.getEpoch(i)
            epoch_string = json.dumps(epoch, separators=(",", ":"))
            sock.send_string(epoch_string)
            time.sleep(timesleep)
        pass


if __name__ == "__main__":
    prot = "tcp://127.0.0.1:5000"
    filename = f'/home/lucas/code/aquarium/data/test.json'
    timesleep = 0.1
    clientZMQ(filename, prot, timesleep)

