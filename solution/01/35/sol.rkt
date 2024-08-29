(define/contract (candy ratings)
  (-> (listof exact-integer?) exact-integer?)
  (define n (length ratings))
  (define left (make-vector n 1))
  (define right (make-vector n 1))
  (define candies 0)

  (for ([i (in-range 1 n)])
    (when (> (list-ref ratings i) (list-ref ratings (- i 1)))
      (vector-set! left i (+ 1 (vector-ref left (- i 1))))))

  (for ([i (in-range (- n 2) -1 -1)])
    (when (> (list-ref ratings i) (list-ref ratings (+ i 1)))
      (vector-set! right i (+ 1 (vector-ref right (+ i 1))))))

  (for ([i (in-range n)])
    (set! candies (+ candies (max (vector-ref left i) (vector-ref right i)))))

  candies)

;; Example usage
(candy '(1 0 2))  ;; Output: 5
