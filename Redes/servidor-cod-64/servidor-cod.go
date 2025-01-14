package main

import (
	"encoding/base64"
	"io/ioutil"
	"net"
)

func handleclient(conn *net.UDPConn) {
	var netBuffer [8000]byte
	var fileBuffer [8000]byte

	conn.Read(netBuffer[0:])

	base64.StdEncoding.Decode(fileBuffer[:], netBuffer[:])

	ioutil.WriteFile("go.jpeg", fileBuffer[:], 0444)
}

func main() {
	service := ":1200"

	udpAddr, _ := net.ResolveUDPAddr("udp", service)
	conn, _ := net.ListenUDP("udp", udpAddr)

	for {
		handleclient(conn)
	}
}
