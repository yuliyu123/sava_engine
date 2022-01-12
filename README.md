# sava_engine
For scan malicious software includes several malware like backdoor, btc miner and malicious bash script, etc.

## It supports features below:
	Intergate Avira Antivirus so it can scan several kinds of malwares inside host.
	Support multithread scan, you can config thread count inside TaskRunner contructor.
	Receive waiting scan tasks from redis queue by hiredis and send results to redis queue.
	Encrypt product id and password by openssl lib.
	Support deployed and running by docker.


## usage
	docker build -f ./Dockerfile  -t sava:v1.0 .
	docker run sava:v1.0
	docker stop {CONTAINER ID}

	docker save -o sava_srv.tar sava:v1.0
	docker load -i sava_srv.tar
