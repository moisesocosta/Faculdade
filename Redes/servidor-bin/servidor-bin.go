package main

import (
	"bytes"
	"encoding/binary"
	"net"
)

type msg struct {
	SensorId uint16
	LocId uint16
	TimeStamp uint32
	Temperature uint16
}

func handleClient(conn *net.UDPConn)  {
	var data msg
	var buffer = make([]byte, 10)

	conn.Read(buffer)

	binary.Read(bytes.NewReader(buffer), binary.BigEndian, &data)

	println("Id do sensor: ", data.SensorId)
	println("Id da localização: ", data.LocId)
	println("Timestamp: ", data.TimeStamp)
	println("Temperatura: ", data.Temperature)
}

func main() {
	service := ":1200"
	addr, _ := net.ResolveUDPAddr("udp", service)
	conn, _ := net.ListenUDP("udp", addr)

	for {
		handleClient(conn)
	}

}
