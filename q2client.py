import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('192.168.217.135', 8080)
print('connecting to 192.168.217.135'.format(*server_address))
sock.connect(server_address)

try:
	fahrenheit = float(input("Enter temp in fahrenheit: "))
	sock.sendall(str(fahrenheit).encode())

	amount_received = 0
	amount_expected = len(str(fahrenheit))

	while amount_received < amount_expected:
		data = sock.recv(16)
		amount_received += len(data)
		celsius = float(data.decode())
		print("temperature in celsius: {} c".format(celsius))
finally:
	sock.close()
