package main
import "fmt"

func sol(a int, b int) int {
   return a + b;
}

func main() {
   var a, b int
   fmt.Scan(&a)
   fmt.Scan(&b)
   fmt.Println(sol(a, b))
}