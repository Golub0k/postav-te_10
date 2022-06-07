FROM gcc:11
WORKDIR /APP
COPY . .
RUN g++ app.cpp -o app.exe
ENTRYPOINT ./app.exe