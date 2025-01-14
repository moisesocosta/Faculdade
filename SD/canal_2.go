package main

import (
	"sync"
	"time"
)

func main() {
	channel := make(chan string, 1)
	var wait sync.WaitGroup

	wait.Add(1)
	go func() {
		channel <- "Hello world!"
		println("Finishing go routine")
		wait.Done()
	}()

	time.Sleep(time.Second)
	message := <-channel
	println(message)
	wait.Wait()
}
