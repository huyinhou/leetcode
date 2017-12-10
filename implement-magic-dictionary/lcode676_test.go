package lcode676

type MagicDictionary struct {
	Origin  map[string]int
	Pattern map[string]int
}

/** Initialize your data structure here. */
func Constructor() MagicDictionary {
	return MagicDictionary{
		Origin:  make(map[string]int),
		Pattern: make(map[string]int),
	}
}

/** Build a dictionary through a list of words */
func (this *MagicDictionary) BuildDict(dict []string) {
	for _, s := range dict {

	}
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
func (this *MagicDictionary) Search(word string) bool {

}
