require 'rubygems'
require 'rubygems/specification'

require 'bundler'
Bundler::GemHelper.install_tasks

$:<< 'lib'

$stdout.puts """
rb_import Copyright (C) 2014 Franck Verrot <franck@verrot.fr>
This program comes with ABSOLUTELY NO WARRANTY; for details type `rake license'.
This is free software, and you are welcome to redistribute it
under certain conditions; type `rake license' for details.

"""

require 'rake/testtask'
Rake::TestTask.new do |t|
  t.libs << "test"
  t.pattern = "test/**/*_test.rb"
  t.verbose = true
  t.warning = true
end

def gemspec
  @gemspec ||= begin
                 file = File.expand_path('../rb_import.gemspec', __FILE__)
                 eval(File.read(file), binding, file)
               end
end

desc "Clean the current directory"
task :clean do
  rm_rf 'tmp'
  rm_rf 'pkg'
end

desc "Run the full spec suite"
task :full => ["clean", "test"]

desc "install the gem locally"
task :install => :package do
  sh %{gem install pkg/#{gemspec.name}-#{gemspec.version}}
end

desc "validate the gemspec"
task :gemspec do
  gemspec.validate
end

desc "Build the gem"
task :gem => [:gemspec, :build] do
  mkdir_p "pkg"
  sh "gem build rb_import.gemspec"
  mv "#{gemspec.full_name}.gem", "pkg"

  require 'digest/sha2'
  built_gem_path = "pkg/#{gemspec.full_name}.gem"
  checksum = Digest::SHA512.new.hexdigest(File.read(built_gem_path))
  checksum_path = "checksums/#{gemspec.version}.sha512"
  File.open(checksum_path, 'w' ) {|f| f.write(checksum) }
end

desc "Install rb_import"
task :install => :gem do
  sh "gem install pkg/#{gemspec.full_name}.gem"
end

task :default => :full

task :license do
  `open http://opensource.org/licenses/MIT`
end

task :console do
  require 'pry'
  Pry.start
end

require 'rake/extensiontask'
spec = Gem::Specification.load('rb_import.gemspec')
Rake::ExtensionTask.new('rb_import', spec) do |ext|
  ext.source_pattern = "*.{c,h}"
end

desc "Run the full spec suite"
task :full => ["clean", "compile", "test"]
