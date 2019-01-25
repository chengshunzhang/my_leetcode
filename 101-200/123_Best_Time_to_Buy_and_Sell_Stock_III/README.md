## Dynamic Programming  
Maintain two arrays: `buy` and `sell`, each of shape (2, n), where n is the number of input.  
`buy[0][i]` means the most money we have at day i with exact 1 purchase.  
`buy[1][i]` means the most money we have at day i with at least 1, at most 2 purchases.  
`sell[0][i]` means the most money we have at day i with at most 1 sell.  
`sell[1][i]` means the most money we have at day i with at most 2 sells.  
  
The transition function is:  
`buy[0][i] = max(buy[0][i - 1], -prices[i])`  
`sell[0][i] = max(sell[0][i - 1], prices[i] - buy[0][i - 1])`  
`buy[1][i] = max(buy[1][i - 1], sell[0][i - 1] - prices[i])`  
`sell[1][i] = max(sell[1][i - 1], prices[i] - buy[1][i - 1])`  
  
By definition, `buy[0][0] = buy[1][0] = -prices[0], sell[0][0] = sell[1][0] = 0`  

## Optimize to O(1) space  
From transition function, we can see that the value in each iteration only depends on one previous value. So we can use buy1, buy2, sell1, sell2, buy1_pre, buy2_pre, sell1_pre and sell2_pre alternatively to reach O(1) space.  
Initialize buy1 = buy2 = INT_MIN, sell1 = sell2 = 0.  
In each iteration, first assign current value to previous value and update current value with the transition function.
