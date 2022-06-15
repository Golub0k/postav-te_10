FROM gcc:11 AS build
WORKDIR /APP
COPY . .
RUN g++ app.cpp -o app.exe
#ENTRYPOINT ./app.exe
FROM ubuntu:07.06
COPY --from=build /APP/app.exe /app.exe
CMD ./app.exe