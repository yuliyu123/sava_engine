# sava_engine
For scan malicious software includes several malwares like backdoor, btc miner and malicious bash script, etc.

## It supports features below:
	1. Intergate Avira Antivirus so it can scan several kinds of malwares inside host.
	2. Support multithread scan, you can config thread count inside TaskRunner contructor.
	3. Receive waiting scan tasks from redis queue by hiredis and send results to redis queue.
	4. Encrypt product id and password by openssl lib.
	5. Support deploy and run on docker.


## usage
	docker build -f ./Dockerfile  -t sava:v1.0 .
	docker run sava:v1.0
	docker stop {CONTAINER ID}

	docker save -o sava_srv.tar sava:v1.0
	docker load -i sava_srv.tar
