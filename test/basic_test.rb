require 'test_helper'
require 'minitest/autorun'

class BasicTest < Minitest::Test
  def test_basic
    f = import("./test/fixtures/foo.rb")
    assert_equal "foo bar", f.new.to_s
  end
end
