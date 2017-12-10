package lcode155

import "testing"

func TestCase1(t *testing.T) {
	s := Constructor()
	s.Push(1)
	s.Push(2)
	s.Push(-1)
	if s.GetMin() != -1 {
		t.Error(1)
	}
	if s.Top() != -1 {
		t.Error(2)
	}
	s.Pop()
	if s.GetMin() != 1 {
		t.Error(3)
	}
	if s.Top() != 2 {
		t.Error(4)
	}
	s.Pop()
	if s.Top() != 1 {
		t.Error(s.Top())
	}
	s.Pop()

	s.Push(-1)
	s.Push(-2)
	s.Push(-31)
	if s.GetMin() != -31 {
		t.Error(1)
	}
	if s.Top() != -31 {
		t.Error(2)
	}
	s.Pop()
	if s.GetMin() != -2 {
		t.Error(3)
	}
	if s.Top() != -2 {
		t.Error(4)
	}
	s.Pop()
	if s.Top() != -1 {
		t.Error(s.Top())
	}
	s.Pop()
}
