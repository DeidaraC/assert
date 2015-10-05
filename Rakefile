task :default => :test

CFLAGS  = "-std=c99 -Wall"

SRC = FileList["**/*.c"]

desc "run unit test"
task :test => :format do
  sh "cc #{CFLAGS} #{SRC} -o test.out"
  sh "./test.out && rm test.out"
end

desc "format code"
task :format do
  format_files = FileList["**/*.c", "**/**.h"].exclude(["deps/**/*"])
  format_files.each do |t|
    output = `clang-format-3.6 -style=llvm #{t}`

    File.open(t, "w") do |file|
      file.puts(output)
    end
  end
end