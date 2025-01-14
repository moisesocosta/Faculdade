package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"net/url"
	"os"
)

func main(){
	if len(os.Args) != 2{
		fmt.Fprintf(os.Stderr, "Uso: %s URL", os.Args[0])
		os.Exit(1)
	}

	url, err := url.ParseRequestURI(os.Args[1])

	if err != nil{
		fmt.Fprintf(os.Stderr, "Erro: %s\n", err.Error())
		os.Exit(1)
	}

	resp, err := http.Get(url.String())

	if err != nil{
		fmt.Fprintf(os.Stderr, "Erro: %s\n", err.Error())
		os.Exit(1)
	}

	data, _ := ioutil.ReadAll(resp.Body)

	fmt.Printf("%s", data)

	resp.Body.Close()

	os.Exit(0)
}