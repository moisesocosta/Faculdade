package main

import (
	"log"
	"net/http"
	"os"
	"os/signal"
	"time"

	"meuexemplo.com/handlers"
)

func main() {
	l := log.New(os.Stdout, "minha-aplicacao", log.LstdFlags)

	meuhandler := handlers.NewHome(l)

	sm := http.NewServeMux()

	sm.Handle("/", meuhandler)

	s := &http.Server{
		Addr:         ":9090",
		Handler:      sm,
		IdleTimeout:  120 * time.Second,
		ReadTimeout:  1 * time.Second,
		WriteTimeout: 1 * time.Second,
	}

	go func() {
		err := s.ListenAndServe()
		if err != nil {
			l.Fatal(err)
		}
	}()
	signalChan := make(chan os.Signal)
	signal.Notify(signalChan, os.Interrupt)
	signal.Notify(signalChan, os.Kill)

	sig := <-signalChan
	l.Println("Encerrando carinhosamente o servidor", sig)

}
