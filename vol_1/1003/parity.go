package main

import "fmt"

type Answer struct {
	low, high int32
	parity bool
}

var answerMap map[int32]Answer

func checkAnswer(low int32, high int32, parity bool) bool {
	 prevAns, ok := answerMap[high]
	 if !ok {
	 	answerMap[high] = Answer{low, high, parity}
	 	return true
	 }

	 if prevAns.low == low && prevAns.high == high {
	 	return prevAns.parity == parity
	 }

	 if prevAns.low < low {
	 	return checkAnswer(prevAns.low, low - 1, prevAns.parity != parity)
	 } else {
	 	return checkAnswer(low, prevAns.low - 1, prevAns.parity != parity)
	 }
}

func sol() {
	var low, high int32
	var parityStr string
	var questionsAsked int32 = 0
	var seqLen, nAnswers int
	for {
		fmt.Scanf("%d\n", &seqLen)
		if seqLen == -1 { // End of tests
			break;
		}
		fmt.Scanf("%d\n", &nAnswers)
		answerMap = make(map[int32]Answer)
		questionsAsked = 0
		var res bool = true
		for i := 0 ; i < nAnswers; i++ {
			fmt.Scanf("%d %d %s\n", &low, &high, &parityStr)
			if res {
				res = checkAnswer(low, high, parityStr == "even")
				questionsAsked++
			}
		}
		//break
		fmt.Printf("%d\n", questionsAsked)
	}
}

func main() {
	sol()
}
