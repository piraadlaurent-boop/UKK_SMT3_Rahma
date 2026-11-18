"use client"

import * as React from "react"
import Link from "next/link"

import {
  NavigationMenu,
  NavigationMenuContent,
  NavigationMenuItem,
  NavigationMenuLink,
  NavigationMenuList,
} from "@/components/ui/navigation-menu"

const components: { title: string; href: string; }[] = [
  {
    title: "Alert Dialog",
    href: "/docs/primitives/alert-dialog",
    
  },
  {
    title: "Hover Card",
    href: "/docs/primitives/hover-card",
    
  },
  {
    title: "Progress",
    href: "/docs/primitives/progress",
   
  },
  {
    title: "Scroll-area",
    href: "/docs/primitives/scroll-area",
    
  },
  {
    title: "Tabs",
    href: "/docs/primitives/tabs",
    
  },
  {
    title: "Tooltip",
    href: "/docs/primitives/tooltip",

  },
]

export function MenuLandingPage() {
  return (
    <NavigationMenu>
      <NavigationMenuList>
        
        <NavigationMenuItem className="hidden md:flex">
          <NavigationMenuContent>
            <ul className="grid w-[400px] gap-2 md:w-[500px] md:grid-cols-2 lg:w-[600px]">
              {components.map((component) => (
                <ListItem
                  key={component.title}
                  title={component.title}
                  href={component.href}
                >
                </ListItem>
              ))}
            </ul>
          </NavigationMenuContent>
        </NavigationMenuItem>
        <NavigationMenuItem>
        </NavigationMenuItem>
      </NavigationMenuList>
    </NavigationMenu>
  )
}

function ListItem({
  title,
  children,
  href,
  ...props
}: React.ComponentPropsWithoutRef<"li"> & { href: string }) {
  return (
    <li {...props}>
      <NavigationMenuLink asChild>
        <Link href={href}>
          <div className="flex flex-col gap-1 text-sm">
            <div className="leading-none font-medium">{title}</div>
            <div className="line-clamp-2 text-muted-foreground">{children}</div>
          </div>
        </Link>
      </NavigationMenuLink>
    </li>
  )
}
