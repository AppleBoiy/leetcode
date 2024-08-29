# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    return 0 if s.empty?
    return 1 if s.length == 1

    max = 0
    start = 0
    hash = {}

    s.each_char.with_index do |c, i|
        if hash.key?(c) && hash[c] >= start
        start = hash[c] + 1
        end
        hash[c] = i
        max = [max, i - start + 1].max
    end

    max
end

def test_length_of_longest_substring
  test_cases = {
    "" => 0,
    "a" => 1,
    "abcabcbb" => 3,
    "bbbbb" => 1,
    "pwwkew" => 3,
    "au" => 2,
    "dvdf" => 3
  }

  test_cases.each do |input, expected|
    result = length_of_longest_substring(input)
    puts "length_of_longest_substring(\"#{input}\") = #{result}; Expected = #{expected}"
    raise "Test failed for input #{input}" unless result == expected
  end
end

test_length_of_longest_substring