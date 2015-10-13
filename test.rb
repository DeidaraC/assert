require 'minitest/autorun'
require "open3"

class TestExpand < Minitest::Test
  CFLAGS = "-std=c99 -Wall"

  def test_assert_success
    `cc #{CFLAGS} assert.c test/test_assert_success.c -o assert_success.out`
    stdout_str, stderr_str, status = Open3.capture3("./assert_success.out")
    assert_equal "", stdout_str
    assert_equal 0, status.exitstatus
    assert_equal "", stderr_str
  end

  def test_assert_fail
    `cc #{CFLAGS} assert.c test/test_assert_fail.c -o assert_fail.out`
    stdout_str, stderr_str, status = Open3.capture3("./assert_fail.out")
    assert_equal "", stdout_str
    assert_equal false, status.exited?
    assert_equal "Assertion failed: (1 == 2), in function: assert2, file: test/test_assert_fail.c, line: 7.\n",
    stderr_str
  end

  def test_assert_ndebug
    `cc #{CFLAGS} assert.c test/test_assert_ndebug.c -o assert_ndebug.out`
    stdout_str, stderr_str, status = Open3.capture3("./assert_ndebug.out")
    assert_equal "", stdout_str
    assert_equal 0, status.exitstatus
    assert_equal "", stderr_str
  end

  def test_assert_multi_include
    `cc #{CFLAGS} assert.c test/test_multi_include.c -o assert_multi_include.out`
    stdout_str, stderr_str, status = Open3.capture3("./assert_multi_include.out")
    assert_equal "", stdout_str
    assert_equal false, status.exited?
    assert_equal "Assertion failed: (1 == 2), in function: assert2, file: test/test_multi_include.c, line: 8.\n",
    stderr_str
  end
end
