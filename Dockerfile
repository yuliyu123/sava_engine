FROM centos:7

#CMD yum -y install hiredis
RUN mkdir -p /root/dev/sava_detecator/bin
ADD ./bin /root/dev/sava_detecator/bin
ADD ./libhiredis.so.1.0.3-dev /root/dev/sava_detecator/bin/
RUN pwd
WORKDIR /root/dev/sava_detecator/bin
RUN pwd
#RUN chmod -R 777 /root/dev/sava_detecator/bin/sava_scan
ENTRYPOINT ["./sava_scan"]
CMD ["mlePCJIY7WxCZtmxFyezjTg==", "127.0.0.1", "eKCfeLNFby+4b//I+maOxxg=="]
