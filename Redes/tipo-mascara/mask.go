package main

import (
	"fmt"
	"net"
	"os"
	"strconv"
)

func main() {
	if len(os.Args) != 4 {
		fmt.Fprintf(os.Stderr, "Uso: %s ip bits-máscara bits-ip.\n", os.Args[0])
		os.Exit(1)
	}

	dotAddr := os.Args[1]
	ones, _ := strconv.Atoi(os.Args[2])
	bits, _ := strconv.Atoi(os.Args[3])

	addr := net.ParseIP(dotAddr)

	if addr == nil {
		fmt.Fprintf(os.Stderr, "Parâmetro %s inválido.\n", dotAddr)
		os.Exit(1)
	}

	mask := net.CIDRMask(ones,bits)

	network := addr.Mask(mask)

	fmt.Println("Endereço: ", addr.String())
	fmt.Println("Máscara: ", mask.String())
	fmt.Println("Rede: ", network.String())

	os.Exit(0)
}
