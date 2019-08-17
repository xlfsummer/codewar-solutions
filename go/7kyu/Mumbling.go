package kata

import ( "strings" )


// https://www.codewars.com/kata/mumbling/train/go
func Accum(s string) string {
	var strs = strings.Split(s, "")
	var resultStrs []string

	for i, code := range strs {
		resultStrs = append(resultStrs, strings.Title(strings.Repeat(strings.ToLower(code), i + 1)))
	}

	return strings.Join(resultStrs, "-")
}

// func main() {
// 	Accum("abc")
// }
