_This project has been created as part of the 42 curriculum by addias_

# Server Infrastructure Project

## Project Description

This project implements a secure Linux server environment with `ssh protocol`, `password policies`, and `monitoring scripts`.

### Operating System Selection

**Debian**  
Chosen for its stability, extensive package repository, and strong community support. Ideal for predictable deployments.

**Rocky Linux**  
Selected as a distribution with enterprise features and long-term support cycles.

### System Design Choices

- **Partitioning**: Separate partitions for system, home, and logs
- **Security**: Implemented mandatory access control and firewall
- **User Management**: Role-based access with strict policies
- **Services**: SSH and UFW

## Technology Comparison

### Debian vs Rocky Linux
| Aspect | Debian | Rocky Linux |
|--------|--------|-------------|
| Base | Independent | RHEL |
| Package Manager | APT | DNF |
| Default Security | AppArmor | SELinux |
| Release Cycle | Stable | Point releases |

### APT vs APTITUDE
| Feature | APT | APTITUDE |
|---------|-----|----------|
| Interface | Command-line tools | Interactive & CLI |
| Dependency Handling | Good | Advanced |
| Conflict Resolution | Basic | Advanced |
| User Experience | Simple commands | Menu-driven interface |

### AppArmor vs SELinux
| Feature | AppArmor | SELinux |
|---------|----------|---------|
| Approach | Path-based | Label-based |
| Complexity | Lower | Higher |
| Default on | Debian | Rocky |

### UFW vs firewalld
| Aspect | UFW | firewalld |
|--------|-----|-----------|
| Simplicity | Very simple | Moderate |
| Management | Basic rules | Zone-based |
| Default OS | Debian | Rocky |

### VirtualBox vs UTM
| Feature | VirtualBox | UTM |
|---------|------------|-----|
| Platform | Multi-OS | macOS focused |
| Performance | Good | Excellent on Apple Silicon |
| Architecture | x86 focus | ARM optimized |


### Sudo Configs

- /etc/sudoers.d/sudo_config
- /var/log/sudo

### Password Polices
- etc/login.defs
- nano etc/pam.d/common-password

### Groups
- sudo adduser `<user>`
- sudo deluser `<user>`
- cat etc/group

### UFW
- sudo ufw allow `<gate>`
- sudo ufw delete `<index>`

### SSH Configs
- etc/ssh/sshd_config

### Users
- etc/passwd