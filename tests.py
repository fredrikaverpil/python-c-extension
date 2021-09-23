import hello


def test_hello():
    assert hello.hello_world() == "hello world"


def test_greet():
    assert hello.greet("fredrik") == "hello FREDRIK"
