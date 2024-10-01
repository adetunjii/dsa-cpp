package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	sharedWork []int
	mut        sync.Mutex
	condVar    = sync.NewCond(&mut)
)

var isReady = false

func producer() {
	sharedWork = []int{1, 0, 3}
	time.Sleep(2 * time.Second)

	mut.Lock()
	isReady = true // change the state
	mut.Unlock()

	condVar.Signal() // notify another thread about the change
}

func worker() {
	fmt.Println("Waiting")

	mut.Lock()
	defer mut.Unlock()

	for !isReady {
		condVar.Wait() // blocks until isReady is true
	}
	sharedWork[1] = 2
	fmt.Println("Done")
}

func main() {
	go producer()
	go worker()

	time.Sleep(3 * time.Second)
	fmt.Println(sharedWork)
}
