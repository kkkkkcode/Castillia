import time

def focus_timer(duration):
    start_time = time.time()
    end_time = start_time + duration*60
    while time.time() < end_time:
        time_left = int(end_time - time.time())
        minutes = time_left // 60
        seconds = time_left % 60
        print(f"Time left: {minutes} minutes, {seconds} seconds")
        time.sleep(1)

    print("Time's up! Focus session over.")

if __name__ == '__main__':
    duration = int(input("Enter the duration of focus session in minutes: "))
    focus_timer(duration)
