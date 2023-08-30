def maxValue(self, n : int, arr : List[int]) -> int:
        # code here
        max_value = 0
        
        right = [0] * n
        right[n - 1] = arr[n - 1]
        
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], arr[i])
        
        left = arr[0]
        
        for i in range(1, n - 1):
            geek_value = (left - arr[i]) * right[i + 1]
            max_value = max(max_value, geek_value)
            left = max(left, arr[i])
        
        return max(max_value, 0)