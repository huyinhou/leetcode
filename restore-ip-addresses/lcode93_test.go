package lcode93

import (
	"fmt"
	"testing"
)

func checkIpPart(strip string, nlen int) bool {
	slen := len(strip)
	if slen < nlen {
		return false
	}
	if nlen == 1 {
		return true
	} else if nlen == 2 {
		c := strip[0]
		return c != '0'
	} else if nlen == 3 {
		c0 := strip[0]
		if c0 == '1' {
			return true
		} else if c0 == '2' {
			c1 := strip[1]
			if c1 < '5' {
				return true
			} else if c1 == '5' {
				c2 := strip[2]
				return c2 <= '5'
			}
		}
	}
	return false
}

func restoreIpAddressesWithParts(prefix string, strip string, npart int) []string {
	slen := len(strip)
	if npart == 1 {
		if slen > 3 || !checkIpPart(strip, slen) {
			return nil
		}
		return []string{fmt.Sprintf("%s.%s", prefix, strip)}
	}

	retval := []string{}
	for i := 1; i <= 3; i++ {
		if !checkIpPart(strip, i) {
			break
		}
		newprefix := fmt.Sprintf("%s.%s", prefix, strip[:i])
		if len(prefix) == 0 {
			newprefix = strip[:i]
		}
		subparts := restoreIpAddressesWithParts(newprefix, strip[i:], npart-1)
		if subparts != nil {
			retval = append(retval, subparts...)
		}
	}
	return retval
}

func restoreIpAddresses(s string) []string {
	return restoreIpAddressesWithParts("", s, 4)
}

func TestCase1(t *testing.T) {
	ret := checkIpPart("", 1)
	if ret != false {
		t.Error(1)
	}
	ret = checkIpPart("0", 1)
	if ret != true {
		t.Error(1)
	}
	ret = checkIpPart("0", 2)
	if ret != false {
		t.Error(1)
	}
	ret = checkIpPart("11", 2)
	if ret != true {
		t.Error(1)
	}
	ret = checkIpPart("1111", 3)
	if ret != true {
		t.Error(1)
	}
	ret = checkIpPart("322", 2)
	if ret != true {
		t.Error(1)
	}
	ret = checkIpPart("3222", 3)
	if ret != false {
		t.Error(1)
	}
	ret = checkIpPart("2602", 3)
	if ret != false {
		t.Error(1)
	}
	ret = checkIpPart("2562", 3)
	if ret != false {
		t.Error(1)
	}
	ret = checkIpPart("2528", 3)
	if ret != true {
		t.Error(1)
	}
}

func TestCase2(t *testing.T) {
	ret := restoreIpAddresses("25525511135")
	fmt.Println(ret)

	ret = restoreIpAddresses("000234")
	fmt.Println(ret)

	ret = restoreIpAddresses("02304")
	fmt.Println(ret)
}
