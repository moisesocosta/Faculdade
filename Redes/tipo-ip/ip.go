package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Fprintf(os.Stderr, "Uso: %s ip-addr.\n", os.Args[0])
		os.Exit(1)
	}

	var addr net.IP = net.ParseIP(os.Args[1])

	if addr == nil {
		fmt.Fprintf(os.Stderr, "Parâmetro %s não é endereço válido.\n", os.Args[1])
		os.Exit(1)
	}

	fmt.Println("O endereço é ",  addr.String())

	os.Exit(0)
}
