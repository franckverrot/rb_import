require 'test_helper'
require 'minitest/autorun'

class BasicTest < Minitest::Test
  def test_basic
    f = import("./test/fixtures/foo.rb")
    assert_equal "foo bar", f.new.to_s
  end

  def test_missing_file
    error_occured = false

    begin
      import("unknown_file.rb")
    rescue LoadError => error
      error_occured = true
    end

    assert error_occured
  end
end
