package main

import (
	"sync"
)

func main() {
	var wait sync.WaitGroup

	wait.Add(1)
	go func(msg string) {
		println(msg)
		defer wait.Done()
	}("Hello world")
	wait.Wait()
}
