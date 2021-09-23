import hello

ret = hello.hello_world()
assert ret == "hello world"

ret = hello.greet("fredrik")
assert ret == "hello FREDRIK"
