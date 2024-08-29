
# @param {String} s
# @return {Integer}
def roman_to_int(s)
    roman = {
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000
    }
    result = 0
    prev = 0
    s.each_char do |c|
        result += roman[c]
        if roman[c] > prev
        result -= 2 * prev
        end
        prev = roman[c]
    end
    result
end

def test_roman_to_int
  test_cases = {
    "III" => 3,
    "IV" => 4,
    "IX" => 9,
    "LVIII" => 58,
    "MCMXCIV" => 1994
  }

  test_cases.each do |input, expected|
    result = roman_to_int(input)
    puts "roman_to_int(\"#{input}\") = #{result}; Expected = #{expected}"
    raise "Test failed for input #{input}" unless result == expected
  end
end

test_roman_to_int