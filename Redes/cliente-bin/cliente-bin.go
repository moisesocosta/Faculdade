package main

import (
	"bytes"
	"encoding/binary"
	"net"
	"os"
	"time"
)

type msg struct {
	SensorId uint16
	LocId uint16
	TimeStamp uint32
	Temperature uint16
}

func main() {

	data := msg {
		SensorId: 1,
		LocId: 3546,
		TimeStamp: uint32(time.Now().Unix()),
		Temperature: 34,
	}

	buffer := new(bytes.Buffer)

	binary.Write(buffer, binary.BigEndian, data)

	service := ":1200"
	addr, _:= net.ResolveUDPAddr("udp", service)
	conn, _ := net.DialUDP("udp", nil, addr)

	conn.Write(buffer.Bytes())

	os.Exit(0)
}