#! /bin/python3
import platform
import subprocess
import os
import argparse


class Command:
    test = False


def main(args: Command):
    currentDir = os.getcwd()
    build_dir = os.path.join(currentDir, "build")

    if not os.path.exists(build_dir):
        os.makedirs(build_dir)
    if platform.system() == "Windows":
        exe = os.path.join(build_dir, "DragonQuest3Clone.exe")
    else:
        exe = os.path.join(build_dir, "DragonQuest3Clone")

    cmake_args = []
    if args.test:
        cmake_args.append("-DTEST=TRUE")

    subprocess.run(["cmake", "-S", ".."] + cmake_args, cwd=build_dir, check=True)
    subprocess.run(["cmake", "--build", ".", "--parallel"], cwd=build_dir, check=True)

    if args.test:
        env = os.environ.copy()
        env["GTEST_COLOR"] = "1"
        subprocess.run(
            ["ctest", "--test-dir", ".", "--output-on-failure", "-j12"],
            cwd=build_dir,
            check=True,
            env=env,
        )
    subprocess.run(exe, cwd=build_dir, shell=True, check=True)


if __name__ == "__main__":
    command = Command()
    parser = argparse.ArgumentParser(description="DragonQuest3Clone Build System")
    parser.add_argument(
        "-t",
        "--test",
        help="Enable Test [Default:Disable]",
        action="store_true",
        default=False,
    )
    args = parser.parse_args(namespace=command)
    main(args)
