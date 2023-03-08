#!/usr/bin/guile \
-e main -s
!#

(use-modules (ice-9 textual-ports))

(define library-files
  '("./src/stack.c"
    "./src/split_buffer.c"))

(define unit-tests
  '("./tests/tests_stack.c"
    "./tests/tests_split_buffer.c"))

(define compile-unit-test
  (lambda (test-file)
    (format #f "gcc ~a ~a -o ~a && ./~a && rm ~a\n"
	    (string-join library-files " ")
	    test-file
	    (basename test-file)
	    (basename test-file)
	    (basename test-file))))

(define main
  (lambda (args)
    (case (string->symbol (list-ref args 1))
      ((all) (format #t "this is a stub for building everything\n"))
      ((tests)
       (for-each (lambda (test)
		   (display (compile-unit-test test))
		   (system (compile-unit-test test)))
		 unit-tests)))))

