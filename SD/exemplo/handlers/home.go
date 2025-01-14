package handlers

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

type Home struct {
	l *log.Logger
}

func NewHome(l *log.Logger) *Home {
	return &Home{l}
}

func (h *Home) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	h.l.Println("Handler Home sendo usado")
	h.l.Println("recebendo requisicao do tipo: ", r.Method)
	log.Println("Recebendo Requisição")
	data, err := ioutil.ReadAll(r.Body)
	if err != nil {
		http.Error(w, "Erro", http.StatusBadRequest)
	}
	fmt.Fprintf(w, "Olá %s\n", data)
}
