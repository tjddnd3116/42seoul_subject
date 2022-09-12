FROM debian:buster

ARG CERTS
ARG KEYS

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="nginx"

# nginx, openssl 설치
RUN apt-get update -y && apt-get install -y nginx && apt-get install openssl

# crt, key 생성
RUN openssl req -newkey rsa:2048 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Gaepo/O=42seoul/OU=Cadet/CN=localhost" -keyout $KEYS -out $CERTS

# 권한 변경후 해당 디렉토리에 복사
RUN chmod +x $KEYS $CERTS
RUN mv $KEYS /etc/ssl/private
RUN mv $CERTS /etc/ssl/certs

# nginx conf 파일 추가
RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/

# nginx daemon 설정
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

# nginx 실행
CMD nginx
