import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("192.168.217.135", 8888))

response = client.recv(4096).decode()
print(response)

client.close()
