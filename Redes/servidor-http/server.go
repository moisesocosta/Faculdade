package main

import (
	"fmt"
	"log"
	"net/http"
)

func helloHandleFunc(w http.ResponseWriter, r *http.Request){
	if r.Method != "GET"{
		http.Error(w, "Method is not supported.", http.StatusMethodNotAllowed)
	}

	fmt.Fprintf(w, "<h1><b>Hello!</b></h1>")
}

func main() {

	fileserver := http.FileServer(http.Dir("./static"))
	http.Handle("/", fileserver)
	http.HandleFunc("/hello", helloHandleFunc)
	
	err := http.ListenAndServe(":8080", nil)

	if err != nil{
		log.Fatal(err)
	}
}