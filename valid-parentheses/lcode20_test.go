package lcode20

import "testing"

func TestCase1(t *testing.T) {
	ret := hashParentheses('{')
	if ret != 1 {
		t.Error(ret)
	}
	ret = hashParentheses('}')
	if ret != -1 {
		t.Error(ret)
	}
	ret = hashParentheses('[')
	if ret != 2 {
		t.Error(ret)
	}
	ret = hashParentheses(']')
	if ret != -2 {
		t.Error(ret)
	}
	ret = hashParentheses('(')
	if ret != 3 {
		t.Error(ret)
	}
	ret = hashParentheses(')')
	if ret != -3 {
		t.Error(ret)
	}
	ret = hashParentheses('a')
	if ret != 0 {
		t.Error(ret)
	}
}

func TestCase2(t *testing.T) {
	ret := isValid("[][][]")
	if !ret {
		t.Error(ret)
	}
	ret = isValid("(ksjdfkdjf")
	if ret {
		t.Error(ret)
	}
	ret = isValid("((())])")
	if ret {
		t.Error(ret)
	}
}
