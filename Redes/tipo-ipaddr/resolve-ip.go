package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Fprintf(os.Stderr, "Uso: %s nome-do-host.\n", os.Args[0])
		os.Exit(1)
	}

	addr, err := net.ResolveIPAddr("ip", os.Args[1])

	if err != nil {
		fmt.Fprintf(os.Stderr, "Erro: %s.\n", err.Error())
		os.Exit(1)
	}

	fmt.Println("Endereço do nome: ", addr.String())

	os.Exit(0)
}
