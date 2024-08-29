defmodule Solution do
  @spec candy(ratings :: [integer]) :: integer
  def candy(ratings) do
    n = length(ratings)
    candies = List.duplicate(1, n)

    candies = Enum.reduce(1..(n - 1), candies, fn i, acc ->
      if Enum.at(ratings, i) > Enum.at(ratings, i - 1) do
        List.replace_at(acc, i, Enum.at(acc, i - 1) + 1)
      else
        acc
      end
    end)

    candies = Enum.reduce((n - 2)..0, candies, fn i, acc ->
      if Enum.at(ratings, i) > Enum.at(ratings, i + 1) do
        List.replace_at(acc, i, max(Enum.at(acc, i), Enum.at(acc, i + 1) + 1))
      else
        acc
      end
    end)

    Enum.sum(candies)
  end
end
