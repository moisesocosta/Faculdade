package main

import (
	"bufio"
	"encoding/base64"
	"net"
	"os"
)

func readImage() []byte {
	file, _ := os.Open("./go.jpeg")
	defer file.Close()

	fileInfo, _ := file.Stat()
	fileSize := fileInfo.Size()
	bytes := make([]byte, fileSize)


	bufferReader := bufio.NewReader(file)
	bufferReader.Read(bytes)

	return bytes
}

func main() {
	binary := readImage()

	enc := base64.StdEncoding.EncodeToString(binary)

	service := ":1200"
	udpAddr, _ := net.ResolveUDPAddr("udp", service)
	conn, _ := net.DialUDP("udp", nil, udpAddr)

	conn.Write([]byte(enc))

	os.Exit(0)
}
